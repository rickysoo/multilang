# OpenAI Multi-language Demo

This package contains example scripts in 7 programming languages that perform basic text completion using the OpenAI API.

## 🔑 Setup
1. Sign up at [https://platform.openai.com](https://platform.openai.com)
2. Get your API key.
3. In your terminal, set the key:
   ```bash
   export OPENAI_API_KEY="sk-..."
   ```

## 📂 Files

- `ai.py` - Python
- `ai.js` - JavaScript (Node.js)
- `ai.ts` - TypeScript (Node.js + tsc)
- `main.rs` - Rust (requires `ureq` and `serde`)
- `main.go` - Go
- `AI.java` - Java
- `ai.cpp` - C++ (calls OpenAI via curl)

## 🧪 Run Examples

Each file can be run individually after setting the `OPENAI_API_KEY` environment variable. You'll also need to install dependencies like:
- Python: `pip install openai`
- Node.js: `npm install openai`
- Rust: add `ureq` and `serde` to `Cargo.toml`
- Java: requires JDK 11+
- C++: requires `curl` and `jq` installed

## ⚠️ Notes
- All use OpenAI's `text-davinci-003` model.
- TypeScript needs to be compiled using `tsc`.
- JavaScript and TypeScript require Node.js.
