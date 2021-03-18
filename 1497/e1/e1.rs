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

const MAXN:usize = 3162;

// with reference
fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let mut square_num:Vec<usize> = vec![0;MAXN+1];
    for i in 1..=MAXN {
        square_num[i] = i * i;
    }
    let mut m:Vec<bool> = vec![false;10000001];
    let t:usize = scan.next();
    let mut l:Vec<usize> = vec![0;10000001];
    
    for _ in 0..t {
        let n:usize = scan.next();
        let _k:usize = scan.next();
        let mut a:Vec<usize> = (0..n).map(|_| scan.next()).collect();

        let mut ans:u32 = 1;
        
        for i in 0..n {
            let temp:usize = a[i];
            if l[temp] != 0 {
                a[i] = l[temp];
                // writeln!(out, "i: {}, a[i]: {}", i, a[i]).ok();
                continue;
            }
            for j in 2..=MAXN {
                if a[i] < square_num[j] {
                    break;
                }
                while a[i] % square_num[j] == 0 {
                    a[i] /= square_num[j];
                }
            }
            // writeln!(out, "temp:{}, a[i]: {}", temp, a[i]).ok();
            l[temp] = a[i];
        }
        
        let mut last = 0;
        for i in 0..n {
            if m[a[i]] == true {
                ans += 1;
                for j in last..i {
                    m[a[j]] = false;
                }
                last = i;
                m[a[i]] = true;
            } else {
                m[a[i]] = true;
            }
        }
        for i in last..n {
            m[a[i]] = false;
        }
        writeln!(out, "{}", ans).ok();
    }
}

