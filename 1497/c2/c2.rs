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
use std::collections::BinaryHeap;

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t:usize = scan.next();
    for _ in 0..t {
        let n:usize = scan.next();
        let k:usize = scan.next();

        let mut ans = BinaryHeap::new();
        ans.push(n);
        for _ in 1..k {
            let i = ans.pop().unwrap();
            // writeln!(out, "{}", i).ok();
            if i & 1 == 1 {
                let mut j = 1;
                while !ans.is_empty() {
                    let k = ans.pop().unwrap();
                    if k != i {
                        ans.push(k);
                        break;
                    } else {
                        j += 1;
                    }
                }
                for _ in 0..j {
                    ans.push(i - 1);
                }
                ans.push(j);
            } else {
                ans.push(i >> 1);
                ans.push(i >> 1);
            }
            // println!("{:?}", ans);
        }
        while !ans.is_empty() {
            write!(out, "{} ", ans.pop().unwrap()).ok();
        }
        writeln!(out, "").ok();
    }
}
