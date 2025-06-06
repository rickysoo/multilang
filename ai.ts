import { Configuration, OpenAIApi } from "openai";

const configuration = new Configuration({
  apiKey: process.env.OPENAI_API_KEY,
});
const openai = new OpenAIApi(configuration);

(async () => {
  const res = await openai.createCompletion({
    model: "text-davinci-003",
    prompt: "AI says:",
    max_tokens: 10,
  });
  console.log("TypeScript:", res.data.choices[0].text.trim());
})();