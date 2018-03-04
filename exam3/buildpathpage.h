#ifndef BUILDPATHPAGE_H
#define BUILDPATHPAGE_H

#include <sstream>
#include "Shortest.h"

void buildpathpage (ostringstream &oss, int port, 
                    vector<string>& events);
                    
#define CLASSIFIED_CGI "classified.cgi"

#endif
