/********************************************************************************
** Form generated from reading UI file 'module_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULE_EDITOR_H
#define UI_MODULE_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModuleUI
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *moduleName;
    QCheckBox *checkBox;
    QGroupBox *group1;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_2;
    QLabel *uppercase_name;
    QLabel *label_4;
    QLabel *camelCase;
    QLabel *label_2;
    QPushButton *testLayout;
    QPushButton *testCmake;
    QPushButton *mainCmake;
    QPushButton *classSrcTemplate;
    QPushButton *classHdrTemplate;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *generate;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addClass;
    QLineEdit *className;
    QListWidget *class_list;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addTest;
    QLineEdit *testName;
    QListWidget *tests_list;
    QGroupBox *templateBox;
    QVBoxLayout *verticalLayout_5;
    QPlainTextEdit *templateText;

    void setupUi(QWidget *ModuleUI)
    {
        if (ModuleUI->objectName().isEmpty())
            ModuleUI->setObjectName(QStringLiteral("ModuleUI"));
        ModuleUI->resize(873, 648);
        gridLayout = new QGridLayout(ModuleUI);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(ModuleUI);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        moduleName = new QLineEdit(ModuleUI);
        moduleName->setObjectName(QStringLiteral("moduleName"));

        horizontalLayout_5->addWidget(moduleName);


        verticalLayout_4->addLayout(horizontalLayout_5);

        checkBox = new QCheckBox(ModuleUI);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);

        verticalLayout_4->addWidget(checkBox);

        group1 = new QGroupBox(ModuleUI);
        group1->setObjectName(QStringLiteral("group1"));
        verticalLayout_6 = new QVBoxLayout(group1);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        uppercase_name = new QLabel(group1);
        uppercase_name->setObjectName(QStringLiteral("uppercase_name"));

        gridLayout_2->addWidget(uppercase_name, 0, 1, 1, 1);

        label_4 = new QLabel(group1);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        camelCase = new QLabel(group1);
        camelCase->setObjectName(QStringLiteral("camelCase"));

        gridLayout_2->addWidget(camelCase, 1, 1, 1, 1);

        label_2 = new QLabel(group1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        testLayout = new QPushButton(group1);
        testLayout->setObjectName(QStringLiteral("testLayout"));

        gridLayout_2->addWidget(testLayout, 6, 1, 1, 1);

        testCmake = new QPushButton(group1);
        testCmake->setObjectName(QStringLiteral("testCmake"));

        gridLayout_2->addWidget(testCmake, 3, 1, 1, 1);

        mainCmake = new QPushButton(group1);
        mainCmake->setObjectName(QStringLiteral("mainCmake"));

        gridLayout_2->addWidget(mainCmake, 2, 1, 1, 1);

        classSrcTemplate = new QPushButton(group1);
        classSrcTemplate->setObjectName(QStringLiteral("classSrcTemplate"));

        gridLayout_2->addWidget(classSrcTemplate, 4, 1, 1, 1);

        classHdrTemplate = new QPushButton(group1);
        classHdrTemplate->setObjectName(QStringLiteral("classHdrTemplate"));

        gridLayout_2->addWidget(classHdrTemplate, 5, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        label_3 = new QLabel(group1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_6->addWidget(label_3);


        verticalLayout_4->addWidget(group1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        generate = new QPushButton(ModuleUI);
        generate->setObjectName(QStringLiteral("generate"));

        verticalLayout_4->addWidget(generate);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(ModuleUI);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(300, 0));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addClass = new QPushButton(groupBox);
        addClass->setObjectName(QStringLiteral("addClass"));

        horizontalLayout_2->addWidget(addClass);

        className = new QLineEdit(groupBox);
        className->setObjectName(QStringLiteral("className"));

        horizontalLayout_2->addWidget(className);


        verticalLayout_3->addLayout(horizontalLayout_2);

        class_list = new QListWidget(groupBox);
        class_list->setObjectName(QStringLiteral("class_list"));

        verticalLayout_3->addWidget(class_list);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ModuleUI);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        addTest = new QPushButton(groupBox_2);
        addTest->setObjectName(QStringLiteral("addTest"));

        horizontalLayout_3->addWidget(addTest);

        testName = new QLineEdit(groupBox_2);
        testName->setObjectName(QStringLiteral("testName"));

        horizontalLayout_3->addWidget(testName);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tests_list = new QListWidget(groupBox_2);
        tests_list->setObjectName(QStringLiteral("tests_list"));

        verticalLayout_2->addWidget(tests_list);


        verticalLayout->addWidget(groupBox_2);


        horizontalLayout->addLayout(verticalLayout);

        templateBox = new QGroupBox(ModuleUI);
        templateBox->setObjectName(QStringLiteral("templateBox"));
        templateBox->setEnabled(true);
        templateBox->setMinimumSize(QSize(250, 0));
        verticalLayout_5 = new QVBoxLayout(templateBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        templateText = new QPlainTextEdit(templateBox);
        templateText->setObjectName(QStringLiteral("templateText"));

        verticalLayout_5->addWidget(templateText);


        horizontalLayout->addWidget(templateBox);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);


        retranslateUi(ModuleUI);
        QObject::connect(checkBox, SIGNAL(toggled(bool)), templateBox, SLOT(setVisible(bool)));
        QObject::connect(checkBox, SIGNAL(toggled(bool)), group1, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(ModuleUI);
    } // setupUi

    void retranslateUi(QWidget *ModuleUI)
    {
        ModuleUI->setWindowTitle(QApplication::translate("ModuleUI", "ModuleEditor", 0));
        label->setText(QApplication::translate("ModuleUI", "Module Name", 0));
        checkBox->setText(QApplication::translate("ModuleUI", "Show advanced features", 0));
        group1->setTitle(QString());
        uppercase_name->setText(QApplication::translate("ModuleUI", "...", 0));
        label_4->setText(QApplication::translate("ModuleUI", "{1}", 0));
        camelCase->setText(QApplication::translate("ModuleUI", "...", 0));
        label_2->setText(QApplication::translate("ModuleUI", "{0}", 0));
        testLayout->setText(QApplication::translate("ModuleUI", "Test Layout", 0));
        testCmake->setText(QApplication::translate("ModuleUI", "Tests CMakeLists.txt", 0));
        mainCmake->setText(QApplication::translate("ModuleUI", "Main CMakeLists.txt", 0));
        classSrcTemplate->setText(QApplication::translate("ModuleUI", "Class Source Template", 0));
        classHdrTemplate->setText(QApplication::translate("ModuleUI", "Class Header Template", 0));
        label_3->setText(QApplication::translate("ModuleUI", "<html><head/><body><p><span style=\" font-weight:600;\">Reserved replacers:</span></p><p><span style=\" font-weight:600;\">{0} : UPPERCASE_MODULE_NAME</span></p><p><span style=\" font-weight:600;\">{1} : camelCaseModuleName</span></p><p><span style=\" font-weight:600;\">{2} : className</span></p><p><span style=\" font-weight:600;\">{3} : test_name</span></p><p><span style=\" font-weight:600;\">{4} : class names</span></p><p><span style=\" font-weight:600;\">{5} : each seperate classname (for class files only)</span></p><p><span style=\" font-weight:600;\">{6} : each seperate testname (for test files only)</span></p><p><span style=\" font-weight:600;\"><br/></span></p></body></html>", 0));
        generate->setText(QApplication::translate("ModuleUI", "Generate", 0));
        groupBox->setTitle(QApplication::translate("ModuleUI", "Classes", 0));
        addClass->setText(QApplication::translate("ModuleUI", "Add Class", 0));
        groupBox_2->setTitle(QApplication::translate("ModuleUI", "Tests", 0));
        addTest->setText(QApplication::translate("ModuleUI", "Add Test", 0));
        templateBox->setTitle(QApplication::translate("ModuleUI", "Template Editing", 0));
    } // retranslateUi

};

namespace Ui {
    class ModuleUI: public Ui_ModuleUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULE_EDITOR_H
