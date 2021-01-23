use std::char;
use std::env;
use std::fs::File;
use std::io::{Read, stdin};

fn interpreter(mut argv: env::Args) -> Result<(), String> {
    let path = argv.nth(1).ok_or("wrong argument")?;
    let mut file = File::open(path).map_err(|e| e.to_string())?;
    let mut codes = String::new();
    file.read_to_string(&mut codes).map_err(|e| e.to_string())?;

    let mut mem: Vec<u8> = Vec::new();
    let mut pos = 0;

    mem.push(0);

    let mut i = 0;
    while i < codes.len() {
        match codes.chars().nth(i).ok_or("Invalid index")? {
            '>' => {
                mem.push(0);
                pos += 1;
            }
            '<' if pos == 0 => return Err("pointer can't be less than 0".to_string()),
            '<' => pos -= 1,
            '+' => mem[pos] = mem[pos].wrapping_add(1),
            '-' => mem[pos] = mem[pos].wrapping_sub(1),
            '.' => print!("{}", mem[pos] as char),
            ',' => {
                let mut s = String::new();
                stdin().read_line(&mut s).ok();
                mem[pos] = s.trim().to_string().chars().nth(0).unwrap() as u8;
            }
            '[' if mem[pos] == 0 => {
                let mut cnt = 1;
                while cnt != 0 {
                    i += 1;
                    if i == codes.len() {
                        return Err("No ]".to_string());
                    }
                    if codes.chars().nth(i).unwrap() == '[' {
                        cnt += 1;
                    } else if codes.chars().nth(i).unwrap() == ']' {
                        cnt -= 1;
                    }
                }
            }
            ']' if mem[pos] != 0 => {
                let mut cnt = 1;
                while cnt != 0 {
                    i -= 1;
                    if i as i32 <= -1 {
                        return Err("No [".to_string());
                    }
                    if codes.chars().nth(i).unwrap() == ']' {
                        cnt += 1;
                    } else if codes.chars().nth(i).unwrap() == '[' {
                        cnt -= 1;
                    }
                }
            }
            _ => {}
        }
        i += 1;
    }

    return Ok(());
}

fn main() {
    match interpreter(env::args()) {
        Ok(_) => {}
        Err(e) => println!("Error: {:?}", e),
    }
}
