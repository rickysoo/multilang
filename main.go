package main

import (
    "bytes"
    "encoding/json"
    "fmt"
    "net/http"
    "os"
)

func main() {
    apiKey := os.Getenv("OPENAI_API_KEY")
    url := "https://api.openai.com/v1/completions"
    payload := map[string]interface{}{
        "model": "gpt-4o-mini",
        "prompt": "AI says:",
        "max_tokens": 10,
    }
    data, _ := json.Marshal(payload)

    req, _ := http.NewRequest("POST", url, bytes.NewBuffer(data))
    req.Header.Add("Authorization", "Bearer "+apiKey)
    req.Header.Add("Content-Type", "application/json")

    client := &http.Client{}
    resp, _ := client.Do(req)
    defer resp.Body.Close()

    var result map[string]interface{}
    json.NewDecoder(resp.Body).Decode(&result)

    text := result["choices"].([]interface{})[0].(map[string]interface{})["text"].(string)
    fmt.Println("Go:", text)
}