use std::env;
use ureq::json;

fn main() {
    let api_key = env::var("OPENAI_API_KEY").expect("API key not set");
    let body = json!({
        "model": "gpt-4o-mini",
        "prompt": "AI says:",
        "max_tokens": 10
    });

    let resp: serde_json::Value = ureq::post("https://api.openai.com/v1/completions")
        .set("Authorization", &format!("Bearer {}", api_key))
        .set("Content-Type", "application/json")
        .send_json(body)
        .unwrap()
        .into_json()
        .unwrap();

    println!("Rust: {}", resp["choices"][0]["text"].as_str().unwrap().trim());
}