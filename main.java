import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public class main {
  public static void main(String args[]) throws IOException {
    
    if(args.length != 1) {
      System.out.println("ファイルが指定されていないか，２つ以上指定されています\n");
      System.exit(-1);
    }

    Path file = Paths.get(args[1]);
    if(!Files.exists(file)){
      System.out.println("そのようなファイルはありません");
      System.exit(-1);
    }
    
    String temp = Files.readString(file);
    String[] src = temp.split("");
    ArrayList<Integer> mem = new ArrayList<>();
    
    int pos = 0;

    for(int i=0; i<temp.length(); i++){
      switch (src[i]) {
        case ">":
          ;
          break;

        case "<":
          if(pos == 0){
            System.out.println("ポインタの値を負にすることはできません");
            System.exit(-1);
          }
          pos--;
          break;
          
        case "+":
          mem.add(pos, mem.get(pos)+1);
          break;

        case "-":
          mem.add(pos, mem.get(pos)-1);
          break;

        case ".":
          // String out;
          // byte[] wow;
          // ByteBuffer buffer = ByteBuffer.allocate(Integer.SIZE / Byte.SIZE);
          // wow = buffer.putInt(mem.get(pos)).array();
          // out = new String(wow, "US-ASCII");
          System.out.print(String.valueOf(mem.get(pos)));
          break;

          case ",":
            InputStreamReader reader = new InputStreamReader(System.in);
            try{
              int in = reader.read();
              mem.add(pos, in);
            }catch(Exception e){
              e.printStackTrace();
            }
            break;
          
          case "[":
            if(mem.get(pos) == 0){
              int cnt = 1;
              while(cnt != 0){
                i++;
                if(i == src.length){
                  System.out.println("対応する']'がありません");
                  System.exit(-1);
                }
                if(src[i] == "[") cnt++;
                else if(src[i] == "]") cnt--;
              }
            }
            break;
          
          case "]":
            if(mem.get(pos) != 0){
              int cnt = 1;
              while(cnt != 0){
                i--;
                if(i < 0){
                  System.out.println("対応する'['がありません");
                  System.exit(-1);
                }
                if(src[i] == "]") cnt++;
                else if(src[i] == "[") cnt--;
              }
            }
            break;

        default:
          break;
      }
    }
    System.out.println("\n処理が終了しました");
  }
}