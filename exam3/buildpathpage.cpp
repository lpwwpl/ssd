#pragma warning(disable:4786)

#include <sstream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <signal.h>
#include <stdio.h>

#include "main.h"
#include "buildpage.h"
#include "buildpathpage.h"
#include "Client.h"
#include "Shortest.h"

using namespace std;

void buildpathpage (ostringstream &oss, int port, 
                    vector<string>& events) {

 	in_addr ip;
	ip = getIP();

	displayPageHeader(oss);

	oss << "<P>" << endl;
	oss << "<FORM ACTION=" << CLASSIFIED_CGI << " METHOD=POST>" << endl;
	oss << "<INPUT NAME=PORT TYPE=hidden VALUE=" << port << ">" << endl;
	oss << "<INPUT NAME=IP TYPE=hidden VALUE=" << inet_ntoa(ip) << ">" << endl;

	vector<string>::iterator it;
	for (it = events.begin(); it != events.end(); it++) {
		oss << *it << "<br>" << endl;
	}

	oss << "<INPUT NAME=COMMAND TYPE=submit VALUE=\"Continue\">" << endl;
	oss << "</FORM>" << "<BR>" << endl;
     
	oss << "</BODY>" << endl;
	oss << "</HTML>" << endl;

}
