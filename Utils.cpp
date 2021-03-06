#include <iostream>
#include <iomanip>
#include <unistd.h> 
#include <limits.h>
#include <sys/utsname.h> 

#include "Utils.h"

auto Utils::isOKSelect() -> bool
{
    char select;
    std::cin >> select;
    if (select != 'Y' && select != 'y') return false;
    return true;
}

auto Utils::inputIntegerValue() -> int
{
    auto value{UNSUCCESSFUL};
    
    while (true)
    {
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(IGNORED_NUM, '\n');  
            std::cout << "Incorrect value entered!" << std::endl;
            std::cout << "Try again: ";
        }
        else
        {
            std::cin.ignore(IGNORED_NUM, '\n');  
            return value;
        }
    }
}

auto Utils::printTimeAndData(const tm& timeinfo) -> void
{
    std::cout << std::setw(2) << std::setfill('0') << std::right << timeinfo.tm_hour << ":";
    std::cout << std::setw(2) << std::setfill('0') << std::right << timeinfo.tm_min << ":";
    std::cout << std::setw(2) << std::setfill('0') << std::right << timeinfo.tm_sec << "   ";

    std::cout << std::setw(2) << std::setfill('0') << std::right << timeinfo.tm_mday << "/";
    std::cout << std::setw(2) << std::setfill('0') << std::right << timeinfo.tm_mon + 1 << "/";
    std::cout << timeinfo.tm_year + 1900 << std::endl;
}

auto Utils::getString(std::string& string, size_t size) -> void
{
    std::cin >> string;
    std::cin.ignore(IGNORED_NUM, '\n');
    if(size && size < string.size()) string.resize(size);
}
auto Utils::getPassword(std::string& password, const std::string& text) -> void
{
	password = std::string(getpass(text.c_str()));
}

auto Utils::getSelfPath(std::string& path) -> void
{
    char buff[PATH_MAX];
    ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);
    if (len != -1)
    {
        for(auto i{len - 1}; i >= 0; --i)
        {
            if(buff[i] != '/' ) continue;
            buff[i+1] = '\0';
      	    path = std::string(buff);
	    break;
	}	
    }
}

auto Utils::printOSVersion() -> void
{
    struct utsname utsname; // ???????????? ?????? ?????????????????? ???????? utsname

    uname(&utsname); // ???????????????? ???????????? ???? ????????????

    std::cout << "OS name: " << utsname.sysname << std::endl; 
    std::cout << "Host name: " << utsname.nodename << std::endl; 
    std::cout << "OS release: " << utsname.release << std::endl; 
    std::cout << "OS version: " << utsname.version << std::endl; 
    std::cout << "Architecture: " << utsname.machine << std::endl; 
}
