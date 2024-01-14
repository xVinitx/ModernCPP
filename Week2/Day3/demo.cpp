#include <curl/curl.h>

#include <iostream>

size_t writeFunction(void* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    char end_point[] {
        "https://min-api.cryptocompare.com/data/"
        "price?fsym=BTC&tsyms=USD,JPY,EUR\0"};

    auto curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, end_point);

        /*
           create string object for responsedata to be stored
        */
        std::string response_string{""};

        /*
            API calls also send header parameters
            (Not applicable in this example because we are not modifying
           anything)
        */

        std::string header_string{""};

        /*
            we need a function that can read response recieve and write it
            (byte-by-byte) into response_string variable.
            This function (writeFunction is defined above)
        */

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);

        /*
          specify where the data has to be written (address of response_string)
        */
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        /*
            specify where header data comes from (location of header_string)
        */
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

        /*
            stores response code after execution of api call in this variable
        */
        long response_code{100};

        /*
            Time taken for API call to complete
        */
        double elapsed{0.0f};

        /*
            after all settings above, finally execute curl
            with on all options provided
        */
        curl_easy_perform(curl);

        /*
            gather info on response code, store it in response_code variable location
            similarly we store elapsed time in it's respective variable location
        */
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);

        /*
            clean up sessio, Reset everything before next request is to be made
        */
        curl_easy_cleanup(curl);

        // session can be terminated by setting surl session object to NULL
        curl = NULL;

        std::cout << response_string <<"\n";
        std::cout << response_code <<"\n";
        std::cout << elapsed <<"\n";
    }
}
    