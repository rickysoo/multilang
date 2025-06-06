import os
import openai

openai.api_key = os.getenv("OPENAI_API_KEY")
response = openai.Completion.create(
    engine="text-davinci-003",
    prompt="AI says:",
    max_tokens=10
)
print("Python:", response.choices[0].text.strip())