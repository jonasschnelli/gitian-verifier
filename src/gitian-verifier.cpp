// Copyright (c) 2015 Jonas Schnelli
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "util.h"

#include <curl/curl.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include "tinyformat.h"

#include <QApplication>
#include <QPushButton>

std::string data; //will hold the url's contents

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{
    for (size_t c = 0; c<size*nmemb; c++)
    {
        data.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
}

std::string HelpMessageCli()
{
    std::string strUsage;
    strUsage += HelpMessageGroup(_("Options:"));
    strUsage += HelpMessageOpt("-?", _("This help message"));

    return strUsage;
}

int main(int argc, char* argv[])
{
	ParseParameters(argc, argv);
    if (mapArgs.count("-?") || mapArgs.count("-help") || mapArgs.count("-version")) {
        std::string strUsage = _("Gitian-Verifier version") + " " + FormatFullVersion() + "\n";
        if (!mapArgs.count("-version")) {
            strUsage += "\n" + _("Usage:") + "\n" +
                  "  gitian-verifier binary-url sigs-url  " + _("verify binary") + "\n";

            strUsage += "\n" + HelpMessageCli();
        }

        fprintf(stdout, "%s", strUsage.c_str());
        return false;
    }

	// Skip switches
	while (argc > 1 && IsSwitchChar(argv[1][0])) {
		argc--;
		argv++;
	}

	//load file example
	// DUMMY
	CURL* curl; //our curl object

    curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, "http://www.jonasschnelli.ch/");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress

    curl_easy_perform(curl);

    std::cout << data;

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    //Start QT Part
    QApplication app (argc, argv);

    QPushButton button ("Hello world !");
    button.show();

    return app.exec();
}