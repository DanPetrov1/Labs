package SecondLab;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ForthTask {
    void completeForthTask() {
        System.out.print("Write the text: ");
        //Pattern pattern = Pattern.compile("((http://|https://)?)((www)?)(\\w{2,}.)+()");
        Pattern pattern = Pattern.compile("((?<scheme>https?)://)?(?<host>([\\w^_\\d]{2,}\\.)*[\\w^_\\d]{2,})(:(?<port>[\\d]+))?(/(?<path>(\\w+/)*\\w+\\.?\\w*))?(\\?(?<query>(\\w+=\\w+[&;])*\\w+=\\w+))?([#%](?<fragment>\\w+))?");
        InsertText insertText = new InsertText();
        ArrayList<String> text = insertText.insertText();
        for(int index = 0; index < text.size(); index++) {
            /*if (matcher.matches()) {
                System.out.println("Correct URL - " + (index+1) + ": " + text.get(index));
            }*/
            boolean count = false;
            if (text.get(index).matches(pattern.pattern())) {
                Matcher matcher = pattern.matcher(text.get(index));
                while (matcher.find()) {
                    if (!count) {
                        System.out.println("Correct URL - the string №" + (index + 1));
                        count = true;
                    }
                    if (matcher.group("scheme") != null)
                        System.out.println("scheme: " + matcher.group("scheme"));
                    if (matcher.group("host") != null)
                        System.out.println("host: " + matcher.group("host"));
                    if (matcher.group("port") != null)
                        System.out.println("port: " + matcher.group("port"));
                    if (matcher.group("path") != null)
                        System.out.println("path: " + matcher.group("path"));
                    if (matcher.group("query") != null)
                        System.out.println("query: " + matcher.group("query"));
                    if (matcher.group("fragment") != null)
                        System.out.println("fragment: " + matcher.group("fragment"));
                }
            }
        }
    }
}
