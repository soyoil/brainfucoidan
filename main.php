<?php

if($argc != 2){
  echo "ファイルが指定されていないか，２つ以上指定されています\n";
  exit(1);
}

if(file_exists($argv[1])){}else{
  echo "そのようなファイルはありません\n";
  exit(1);
}

$temp = file($argv[1], FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

$src = $temp[0];

for ($i = 1; $i < count($temp); $i++) { 
  $src .= $temp[$i];
}

$mem = array_fill(0, 30000, 0);

$pos = 0;

$bf = str_split($src);

for($i = 0; $i < count($bf); $i++){
  switch ($bf[$i]) {
    case '>':
      $pos++;
      if($pos == count($mem)) $pos = array_pad($mem, (count($mem)*2), 0);
      break;

    case '<':
      if($pos == 0){
        echo "ポインタの値を負にすることはできません\n";
        exit(1);
      }
      $pos--;
      break;

    case '+':
      $mem[$pos]++;
      break;
    
    case '-':
      $mem[$pos]--;
      break;

    case '.':
      echo chr($mem[$pos]);
      break;

    case ',':
      $mem[$pos] = fscanf(STDIN, '%c');
      break;
    
    case '[':
      if($mem[$pos] == 0){
        $cnt = 1;
        while($cnt != 0) {
          $i++;
          if($i == count($bf)){
            echo "対応する']'がありません\n";
            exit(1);
          }
          if($bf[$i] == '[') $cnt++;
          elseif($bf[$i] == ']') $cnt--;
        }
      }
      break;

    case ']':
      if($mem[$pos] != 0){
        $cnt = 1;
        while($cnt != 0){
          $i--;
          if($i < 0){
            echo "対応する'['がありません\n";
            exit(1);
          }
          if($bf[$i] == ']') $cnt++;
          elseif($bf[$i] == '[') $cnt--;
        }
      }
      break;
    
    default:
      break;
  }
}
echo "\n処理が完了しました\n";
exit(0);