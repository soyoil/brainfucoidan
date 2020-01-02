import sys
import os

if(len(sys.argv) != 2):
  print("ファイルが指定されていないか，２つ以上指定されています")
  exit()

if not(os.path.isfile(sys.argv[1])):
  print("そのようなファイルはありません")
  exit()

with open(sys.argv[1], "r") as f:
  src = f.read()

mem = [0] * 30000
pos = 0
i = 0
while(i < len(src)):
  if(src[i] == ">"):
    pos += 1
    if(pos == len(mem)):
      mem += [0] * 30000
    
  elif(src[i] == "<"):
    if(pos == 0):
      print("ポインタの値を負にすることはできません")
      exit()
    pos -= 1

  elif(src[i] == "+"):
    mem[pos] += 1

  elif(src[i] == "-"):
    mem[pos] -= 1

  elif(src[i] == "."):
    print(chr(mem[pos]), end = "")

  elif(src[i] == ","):
    mem[pos] = ord(int(input()))

  elif(src[i] == "["):
    if(mem[pos] == 0):
      cnt = 1
      while(cnt != 0):
        i += 1
        if(i == len(src)):
          print("対応する']'がありません")
          exit()
        if(src[i] == "["):
          cnt += 1
        elif(src[i] == "]"):
          cnt -= 1
    
  elif(src[i] == "]"):
    if(mem[pos] != 0):
      cnt = 1
      while(cnt != 0):
          i -= 1
          if(i < 0):
            print("対応する'['がありません")
            exit()
          if(src[i] == "]"):
            cnt += 1
          elif(src[i] == "["):
            cnt -= 1

  i += 1

print("\n処理が終了しました")
  