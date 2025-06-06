const { Configuration, OpenAIApi } = require("openai");

const configuration = new Configuration({
  apiKey: process.env.OPENAI_API_KEY,
});
const openai = new OpenAIApi(configuration);

(async () => {
  const res = await openai.createCompletion({
    model: "gpt-4o-mini",
    prompt: "AI says:",
    max_tokens: 10,
  });
  console.log("JavaScript:", res.data.choices[0].text.trim());
})();