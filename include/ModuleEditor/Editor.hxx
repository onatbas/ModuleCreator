#pragma once 

#include "ui_module_editor.h"
#include <QWidget>
#include <qstring.h>
#include <boost/filesystem.hpp>
#include <QFileDialog>

class Editor : public Ui::ModuleUI, public QWidget
{ 
public: 
	Editor(); 
	~Editor(); 

private:
    QString appPath, 
            test_template,
            class_src_template,
            class_hdr_template,
            main_cmake_template,
            test_cmake_template;

    std::string test_template_content,
                class_src_template_content,
                class_hdr_template_content,
                main_cmake_template_content,
                test_cmake_template_content;


    
    void addedTest(QString test_name);
    void addedClass(QString class_name);

    void connectSignals();
    void readContent();
    void generateModule();
    void saveTemplates(); // called in gnerate module
    std::string replace(std::string from, std::string className = "", std::string testName = "");
    
    std::string getClasses();
    std::string getTestNames();

    std::string *current_editable_template;
	 
};