#include <iostream>

#include "wnetwrap.h"


using namespace wrap;
using namespace std;
int main()
{

	req my_request; //GET method used by default
					

	my_request.set_header( "Connection" , "keep-alive" );
	my_request.set_header("Referer", "bla.com");

	resp my_response = HttpsRequest("https://github.com/whoshuu/cpr/archive/refs/tags/1.6.0.zip", my_request, "dl");
	
	cout << "security protocol: " + my_response.protocol << endl;
	cout << endl << "sent headers map:" << endl;
	for (auto elem : my_request.headers)
	{
		cout << elem.first + " : " + elem.second + "\r\n";
	}
	cout << endl << "sent headers map:" << endl;
	for (auto elem : my_response.sent_headers)
	{
		cout << elem.first + " : " + elem.second + "\r\n";
	}
	cout << endl << "recd headers map:" << endl;
	for (auto elem : my_response.received_headers)
	{
		cout << elem.first + " : " + elem.second + "\r\n";
	}
	cout << my_response.text << endl;
	//cout << "recd header: " + my_response.get_header("Referer") << std::endl;
	//cout << "sent header: " + my_response.get_header("ReferEr", "sent") << std::endl;
/*
	my_request.method = "POST";
	my_request.set_header("Content-Type:", "application/json");
	my_request.postdata = "{\"b\":\"a\"}";
	my_response = HttpsRequest("https://postman-echo.com/post", my_request);

	cout << my_response.raw << endl;

	cout << "sent headers map:" << endl;
	for (auto elem : my_response.sent_headers)
	{
		cout << elem.first + " : " + elem.second + "\r\n";
	}

	cout << "recd headers map:" << endl;
	for (auto elem : my_response.received_headers)
	{
		cout << elem.first + " : " + elem.second + "\r\n";
	}

	*/
	return 0;
}


