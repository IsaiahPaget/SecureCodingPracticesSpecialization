```java
import java.io.Console;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.math.BigInteger;

public class Main {
 public static void main(String[] args) {
     Console console = System.console();
     if (console == null) {
         System.out.println("No console available");
         return;
     }

     char[] passwordArray = console.readPassword("Enter your password: ");
     String password = new String(passwordArray);

     byte[] salt = generateSalt(16);
     String saltString = new BigInteger(1, salt).toString(16);

     try {
         MessageDigest md = MessageDigest.getInstance("MD5");
         md.update(salt);
         md.update(password.getBytes());
         byte[] digest = md.digest();
         BigInteger no = new BigInteger(1, digest);
         String hashtext = no.toString(16);
         while (hashtext.length() < 32) {
             hashtext = "0" + hashtext;
         }
         System.out.println("MD5 Hash with salt: " + saltString + hashtext);
     } catch (NoSuchAlgorithmException e) {
         throw new RuntimeException(e);
     }
 }

 public static byte[] generateSalt(int length) {
     SecureRandom sr = new SecureRandom();
     byte[] salt = new byte[length];
     sr.nextBytes(salt);
     return salt;
 }
}

```