// testclient.cpp
//有发现测的不对的请反馈，谢谢！

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "Client.h"

bool testConstructors(void);
bool testverifyPasswd(void);
bool testInsertion(void);

int main(int argc, char* argv[]) {

    if (!testConstructors()) {
       cerr << "Constructor and\\or accessors failed check\n";
       return EXIT_FAILURE;
    }

    if (!testverifyPasswd()) {
       cerr << "Client::verifyPasswd(string passwd) failed check\n";
       return EXIT_FAILURE;
    }

    if (!testInsertion()) {
       cerr << "Operator >> failed check\n";
       return EXIT_FAILURE;
    }

    cout << "All tests passed\n";

    return EXIT_SUCCESS;
}

bool testInsertion(void) {

    stringstream s;
    s << "Li\nJun\nlijun@sina.com\n111111";
    
    Client cl0;
    s >> cl0;

	if (cl0.getFname() == "Li" &&
        cl0.getLname() == "Jun" &&
        cl0.getEmail() == "lijun@sina.com" &&
        cl0.getPasswd() == "111111") {
    
        return true;   
    }
    else {
        return false;
    }
}

bool testConstructors(void) {

	string fn = "Wang";
	string ln = "Ming";
	string em = "qufanxin_85@msn.com";
	string pa = "123456";
    
	Client cl1(fn, ln, em, pa);
    Client cl2;
	Client cl3(cl1);

	cl2.setPasswd("654321");		//测试set...函数
    
    if (cl1.getFname() == "Wang" &&
        cl1.getLname() == "Ming" &&
        cl1.getEmail() == "qufanxin_85@msn.com" &&
        cl1.getPasswd() == "123456" &&

        cl2.getFname() == "" &&
        cl2.getLname() == "" &&
        cl2.getEmail() == "" &&
        cl2.getPasswd() == "654321" &&

		cl3.getFname() == "Wang" &&
        cl3.getLname() == "Ming" &&
        cl3.getEmail() == "qufanxin_85@msn.com" &&
        cl3.getPasswd() == "123456") {

        return true;   
    }
    else {
        return false;
    }
}

bool testverifyPasswd(void) {

	Client cl4;
	cl4.setPasswd("ssd5exe1");

	return cl4.verifyPasswd("ssd5exe1");
}
