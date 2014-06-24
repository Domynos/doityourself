#ifndef PROJECT_H
#define PROJECT_H

#include "page.h"
#include <vector>
#include <string>

class Project
{
public:
    Project();
    void addPage(Page&);
    Page getPage(std::string);

private :
    std::vector<Page> pageList;
};

#endif // PROJECT_H
