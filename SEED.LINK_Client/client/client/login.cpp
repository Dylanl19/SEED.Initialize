#include "login.h"

using namespace client;
[STAThreadAttribute]                  
int main() {
	login Login;                     
	Login.ShowDialog();             
	return 0;
}

