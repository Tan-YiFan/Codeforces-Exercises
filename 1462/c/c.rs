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

    let t:usize = scan.next();
    for _ in 0..t {
        let mut n:u32 = scan.next();
        let mut ans:Vec<u32> = vec![0;0];
        let mut i:u32 = 9;
        while i > 0 {
            if i >= n {
                ans.push(n);
                break;
            } else {
                ans.push(i);
                n -= i;
                i -= 1;
            }
        }
        if i == 0 {
            writeln!(out, "-1").ok();
        } else {
            ans.reverse();
            for i in ans {
                write!(out, "{}", i).ok();
            }
            writeln!(out, "").ok();
        }
    }
}