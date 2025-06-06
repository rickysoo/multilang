#include <cstdlib>
#include <iostream>

int main() {
    std::string cmd = R"(curl https://api.openai.com/v1/completions   -H "Content-Type: application/json"   -H "Authorization: Bearer $OPENAI_API_KEY"   -d '{"model":"text-davinci-003","prompt":"AI says:","max_tokens":10}'   -s | jq -r '.choices[0].text')";
    system(cmd.c_str());
    return 0;
}