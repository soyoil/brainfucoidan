#include <bits/stdc++.h>
#define MEMORY 30000

int main(int argc, char *argv[]){

  // 引数が2ではない（ファイルが指定されていなかったり，二個以上指定されている）時にエラーを返す
  if(argc != 2){
    std::cerr << "ファイルが指定されていないか，２つ以上指定されています" << std::endl;
    return -1;
  }

  // ifs ステートメントでファイルを開く
  std::ifstream ifs(argv[1]);

  // fail メゾットでファイルの存在を調べ，なければエラーを返す
  if(ifs.fail()){
    std::cerr << "そのようなファイルはありません" << std::endl;
    return -1;
  }

  std::string src = "";
  std::string temp;

  // getline メゾットで一行ずつ読み込み，append関数で末尾に文字列を付け足して全体を1行に直す
  while(getline(ifs, temp)) src.append(temp);

  // vectorステートメントでunsigned char型が入る30000個の配列を作り，0で初期化する．
  std::vector<unsigned char> mem(MEMORY, 0);

  // ポインタの位置として変数posを宣言する
  unsigned int pos = 0;

  // size 関数で文字列のサイズを取得し，1文字づつ処理を進める
  for(int i = 0; i < (int)src.size(); i++){
    switch(src[i]){

      case '>': // ポインタのインクリメント
        pos++;
        if(pos == mem.size()) mem.resize(mem.size() * 2, 0); // メモリが足りなければ拡張する
        break;

      case '<': // ポインタのデクリメント
        if(pos == 0){
          std::cerr << "ポインタの値を負にすることはできません" << std::endl;
          return -1;
        }
        pos--;
        break;

      case '+': // メモリのインクリメント
        mem[pos]++;
        break;

      case '-': // メモリのデクリメント 
        mem[pos]--;
        break;

      case '.': // メモリの値が示す文字列の出力
        putchar(mem[pos]);
        break;

      case ',': // 入力された値をメモリに格納
        mem[pos] = getchar();
        break;

      case '[': // ポインタの値が0なら，対応する]の直後にジャンプする
        if(mem[pos] == 0){
          int cnt = 1;
          while(cnt != 0){
            i++;
            // 探索が終端まで達してしまったらエラーを返す
            if(i == src.length()){
              std::cerr << "対応する']'がありません" << std::endl;
              return -1;
            }
            // 入れ子の[]を考慮している
            if(src[i] == '[') cnt++;
            else if(src[i] == ']') cnt--;
          }
        }
        break;

      case ']': // ポインタの値が0でないなら，対応する[の直後にジャンプする
        if(mem[pos] != 0){
          int cnt = 1;
          while(cnt != 0){
            i--;
            // 探索が先頭まで達してしまったらエラーを返す
            if(i < 0){
              std::cerr << "対応する'['がありません" << std::endl;
              return -1;
            }
            if(src[i] == ']') cnt++;
            else if(src[i] == '[') cnt--;
          }
        }
        break;

      default:
        break;
    }
  }
  std::cout << std::endl << "処理が終了しました" << std::endl;
  return 0;
}