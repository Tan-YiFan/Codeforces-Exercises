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
        let n:usize = scan.next();
        let a:Vec<usize> = (0..n).map(|_| scan.next()).collect();
        let mut pref:Vec<usize> = vec![0;n];
        pref[0] = a[0];
        for i in 1..n {
            pref[i] = pref[i - 1] + a[i];
        }
        let mut ans = 0;
        while ans < n - 1 {
            if pref[n - 1] % (n - ans) == 0 {
                let item = pref[n - 1] / (n - ans);
                let mut i = 0;
                let mut ok = true;
                for j in 1..(n-ans) {
                    while pref[i] < item * j {
                        i += 1;
                    }
                    if i >= n || pref[i] > item * j {
                        ok = false;
                        break;
                    } 
                }
                if ok {
                    break;
                }
            }    
            ans += 1;
        }

        writeln!(out, "{}", ans).ok();
    }
}