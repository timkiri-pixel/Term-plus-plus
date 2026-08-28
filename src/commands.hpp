#pragma once

#include <string>

void sayHello(std::string& name);
void run_ls(const std::string& path = ".");
void run_mkdir(const std::string& arg);
void run_cd(const std::string& arg);
void run_touch(const std::string& arg);
void run_cat(const std::string& arg);
void run_catAppend(const std::string& arg, const std::string& delimiter);
std::string run_pwd();
