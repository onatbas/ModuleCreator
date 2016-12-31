#include "Editor.hxx"

#include <sstream>
#include <iostream>

inline void readTempFromTo(QString from, std::string &to)
{
    if (boost::filesystem::exists(from.toStdString())) {
        auto s = std::ifstream(from.toStdString());
        to.assign(
			std::istreambuf_iterator<char>(s),
			std::istreambuf_iterator<char>()
			);
    }
}


inline void writeToFile(std::string from, QString &to)
{
    std::ofstream out(to.toStdString());
    out << from;
}



std::string Editor::replace(std::string from, std::string className, std::string testName)
{
    QString targ = QString::fromStdString(from);
    targ.replace("{0}", uppercase_name->text());
    targ.replace("{1}", camelCase->text());
    // 
    targ.replace("{3}", QString::fromStdString(getTestNames()));
    targ.replace("{4}", QString::fromStdString(getClasses()));

    targ.replace("{5}", QString::fromStdString(className));
    targ.replace("{6}", QString::fromStdString(testName));
    return targ.toStdString();
}


QString toCamelCase(const QString& s)
{
    QStringList parts = s.split('_', QString::SkipEmptyParts);
    for (int i=1; i<parts.size(); ++i)
        parts[i].replace(0, 1, parts[i][0].toUpper());

    return parts.join("");
}

Editor::Editor() : 
    appPath(QApplication::applicationDirPath()),
    current_editable_template(NULL)
{
    setupUi(this);

    test_template = appPath + "/test_template.txt";
    class_src_template = appPath + "/class_src_template.txt";
    class_hdr_template = appPath + "/class_hdr_template.txt";
    main_cmake_template = appPath + "/main_cmake_template.txt";
    test_cmake_template = appPath + "/test_cmake_template.txt";


    connectSignals();
    readContent();


}

Editor::~Editor()
{

}


void Editor::readContent()
{
    readTempFromTo(test_template, test_template_content);
    readTempFromTo(class_src_template, class_src_template_content);
    readTempFromTo(class_hdr_template, class_hdr_template_content);
    readTempFromTo(main_cmake_template, main_cmake_template_content);
    readTempFromTo(test_cmake_template, test_cmake_template_content);
}

void Editor::connectSignals()
{

    QObject::connect( addClass, &QPushButton::clicked, [&](bool doesnt_matter){
        addedClass(className->text());
    });
    QObject::connect( addTest, &QPushButton::clicked, [&](bool doesnt_matter){
        addedTest(testName->text());
    });

    QObject::connect(moduleName, &QLineEdit::textChanged, [&](const QString &newText){
        uppercase_name->setText(newText.toUpper());
        camelCase->setText(toCamelCase(newText));
    });

    QObject::connect(templateText, &QPlainTextEdit::textChanged, [&](){
        if (current_editable_template != NULL)
            *current_editable_template = templateText->toPlainText().toStdString();
    });

    QObject::connect(mainCmake, &QPushButton::clicked, [&](bool dont_care){
        current_editable_template = &main_cmake_template_content;     
        templateText->setPlainText(QString::fromStdString(*current_editable_template));

    });
    QObject::connect(testCmake, &QPushButton::clicked, [&](bool dont_care){
        current_editable_template = &test_cmake_template_content;       
        templateText->setPlainText(QString::fromStdString(*current_editable_template));

    });
    QObject::connect(classSrcTemplate, &QPushButton::clicked, [&](bool dont_care){
        current_editable_template = &class_src_template_content;      
        templateText->setPlainText(QString::fromStdString(*current_editable_template));

    });
    QObject::connect(classHdrTemplate, &QPushButton::clicked, [&](bool dont_care){
        current_editable_template = &class_hdr_template_content;      
        templateText->setPlainText(QString::fromStdString(*current_editable_template));

    });
    QObject::connect(testLayout, &QPushButton::clicked, [&](bool dont_care){
        current_editable_template = &test_template_content;   
        templateText->setPlainText(QString::fromStdString(*current_editable_template));

    });

    QObject::connect(generate, &QPushButton::clicked, [&](bool dont_care){
        generateModule();
    });
}

void Editor::saveTemplates()
{
    writeToFile(test_template_content, test_template);
    writeToFile(class_hdr_template_content, class_hdr_template);
    writeToFile(class_src_template_content, class_src_template);
    writeToFile(main_cmake_template_content, main_cmake_template);
    writeToFile(test_cmake_template_content, test_cmake_template);
}

void Editor::generateModule()
{
    saveTemplates();
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
        "/home",
        QFileDialog::ShowDirsOnly
        | QFileDialog::DontResolveSymlinks);

    dir += "/" + camelCase->text();


    QString include_dir = dir  + "/include/" + camelCase->text();
    QString cmakes_dir  = dir  + "/cmake";
    QString tests_dir   = dir  + "/tests";
    QString tests_mat_dir = dir  + "/tests/materials";
    QString source_dir  = dir  + "/src";


    boost::filesystem::create_directories(include_dir.toStdString());
    boost::filesystem::create_directories(cmakes_dir.toStdString());
    boost::filesystem::create_directories(tests_mat_dir.toStdString());
    boost::filesystem::create_directories(source_dir.toStdString());


    std::ofstream mainCmake(QString(dir + "/CMakeLists.txt").toStdString());
    mainCmake << replace(main_cmake_template_content);

    std::ofstream testsCmake(QString(tests_dir + "/CMakeLists.txt").toStdString());
    testsCmake << replace(test_cmake_template_content);

    for (int i = 0 ; i < class_list->count() ; i++)
    {
        QString t = class_list->item(i)->text();

        std::ofstream class_doc(QString(source_dir + "/" + t + ".cxx").toStdString()); 
        class_doc << replace(class_src_template_content, t.toStdString(), "");

        std::ofstream include_doc(QString(include_dir + "/" + t + ".hxx").toStdString()); 
        include_doc << replace(class_hdr_template_content, t.toStdString(), "");
    }


    for (int i = 0 ; i < tests_list->count() ; i++)
    {
        QString t = tests_list->item(i)->text();

        std::ofstream test_doc(QString(tests_dir + "/" + t + ".cxx").toStdString()); 
        test_doc << replace(test_template_content, "", t.toStdString());
    }


    auto source_cmake_dir = QString(appPath + "/cmake").toStdString();
    if (boost::filesystem::exists(source_cmake_dir))
    {
        boost::filesystem::directory_iterator dir_iter(source_cmake_dir), end;
        while (dir_iter != end)
        {
            if (dir_iter->path() == appPath.toStdString()) 
                continue;

            std::ifstream configure_cmake_file(dir_iter->path().string());
            std::ofstream output_cmake_file(QString(cmakes_dir + "/" + QString::fromStdString(dir_iter->path().filename().string())).toStdString()); 

            output_cmake_file << std::string(                                            
                std::istreambuf_iterator<char>(configure_cmake_file),     
                std::istreambuf_iterator<char>()
                );

            ++dir_iter;
        }
    }

}

void Editor::addedTest(QString test_name)
{
    tests_list->addItem(test_name);
}

void Editor::addedClass(QString class_name)
{
    class_list->addItem(class_name);
}


std::string Editor::getClasses()
{
    std::stringstream ss;
    for (int i = 0 ; i < class_list->count() ; i++)
    {
        auto t = class_list->item(i);
        ss << t->text().toStdString() << " ";
    }

    return ss.str();
}

std::string Editor::getTestNames()
{
    std::stringstream ss;
    for (int i = 0 ; i < tests_list->count() ; i++)
    {
        auto t = tests_list->item(i);
        ss << t->text().toStdString() << " ";
    }

    return ss.str();
}

