#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    const char* apiKey = std::getenv("OPENAI_API_KEY");
    if(!apiKey) {
        std::cerr << "OPENAI_API_KEY not set" << std::endl;
        return 1;
    }

    CURL* curl = curl_easy_init();
    if(!curl) return 1;

    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/completions");
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    std::string auth = std::string("Authorization: Bearer ") + apiKey;
    headers = curl_slist_append(headers, auth.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    nlohmann::json body = {
        {"model", "gpt-4o-mini"},
        {"prompt", "AI says:"},
        {"max_tokens", 10}
    };
    std::string bodyStr = body.dump();
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, bodyStr.c_str());

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    if(res != CURLE_OK) {
        std::cerr << "Request failed" << std::endl;
        return 1;
    }

    auto json = nlohmann::json::parse(response);
    std::cout << json["choices"][0]["text"].get<std::string>() << std::endl;
    return 0;
}
