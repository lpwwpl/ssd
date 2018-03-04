#include <iostream>
#include <string>
#include "Date.h"
#include "Advertisement.h"
#include "Client.h"
using namespace std;
int main(){	
Advertisement dt;	
cin >> dt;
cout<<dt.getStart().getDay();
}