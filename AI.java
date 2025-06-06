import java.io.*;
import java.net.*;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;

public class AI {
    public static void main(String[] args) throws Exception {
        String apiKey = System.getenv("OPENAI_API_KEY");
        URL url = new URL("https://api.openai.com/v1/completions");
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();
        conn.setRequestMethod("POST");
        conn.setRequestProperty("Authorization", "Bearer " + apiKey);
        conn.setRequestProperty("Content-Type", "application/json");
        conn.setDoOutput(true);

        String data = "{\"model\":\"gpt-4o-mini\",\"prompt\":\"AI says:\",\"max_tokens\":10}";
        try (OutputStream os = conn.getOutputStream()) {
            byte[] input = data.getBytes("utf-8");
            os.write(input, 0, input.length);
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(conn.getInputStream(), "utf-8"));
        StringBuilder response = new StringBuilder();
        String responseLine;
        while ((responseLine = br.readLine()) != null) {
            response.append(responseLine.trim());
        }
        String output = response.toString();
        ObjectMapper mapper = new ObjectMapper();
        JsonNode root = mapper.readTree(output);
        String text = root.path("choices").get(0).path("text").asText();
        System.out.println("Java: " + text.trim());
    }
}
