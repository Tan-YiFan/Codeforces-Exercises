/* https://codeforces.com/blog/entry/67391 */
#[allow(unused_imports)]
use std::cmp::{min, max};
use std::io::{BufWriter, stdin, stdout, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t:i32 = scan.next();
    
    for _ in 0..t {
        let n = scan.next::<usize>();
        let a:Vec<i32> = (0..n).map(|_| scan.next()).collect();

        let mut ans:Vec<i32> = (0..n).map(|_| 0).collect();
        for (i, x) in a.iter().enumerate() {
            let mut min_index = 0;
            for j in 0..30 {
                if abs(x - (1 << j)) < abs(x - (1 << min_index)) {
                    min_index = j;
                }
            }
            ans[i] = 1 << min_index;
        }
        
        for (i, x) in ans.iter().enumerate() {
            write!(out, "{}", x).ok();
            if i == n - 1 {
                write!(out, "\n").ok();
            } else {
                write!(out, " ").ok();
            }
        }
    }
}

fn abs(i:i32) -> i32 {
    if i < 0 {
        -i
    } else {
        i
    }
}