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

const MAXN:usize = 5000000 + 10;
fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n = scan.next::<usize>();
    let a:Vec<usize> = (0..n).map(|_| scan.next()).collect();

    let mut ans = false;
    let mut ans1 = 0;
    let mut ans2 = 0;
    let mut ans3 = 0;
    let mut ans4 = 0;
    
    let mut x = vec![vec![]; MAXN];
    let mut sz = vec![0; MAXN];
    for i in 0..n {
        for j in i+1..n {
            let k:usize = a[i] + a[j];
            // writeln!(out, "k: {}", k).ok();
            x[k].push(i);
            x[k].push(j);
            sz[k] += 2;
            if sz[k] == 4 {
                if x[k][0] != x[k][2] &&
                   x[k][1] != x[k][2] && 
                   x[k][1] != x[k][3] {
                    ans = true;
                    ans1 = x[k][0];
                    ans2 = x[k][1];
                    ans3 = x[k][2];
                    ans4 = x[k][3];
                    break;
                }
            } else if sz[k] == 6 {
                if x[k][2] != x[k][4] &&
                   x[k][3] != x[k][4] &&
                   x[k][3] != x[k][5] {
                    ans = true;
                    ans1 = x[k][2];
                    ans2 = x[k][3];
                    ans3 = x[k][4];
                    ans4 = x[k][5];
                    break;
                } else if x[k][0] != x[k][4] &&
                          x[k][1] != x[k][4] &&
                          x[k][1] != x[k][5] {
                    ans = true;
                    ans1 = x[k][0];
                    ans2 = x[k][1];
                    ans3 = x[k][4];
                    ans4 = x[k][5];
                    break;
                }
            } else if sz[k] == 8 {
                ans = true;
                if x[k][0] == x[k][2] && /* pick 1 3 5 7 */
                   x[k][2] == x[k][4] &&
                   x[k][4] == x[k][6] {
                    ans1 = x[k][1];
                    ans2 = x[k][3];
                    ans3 = x[k][5];
                    ans4 = x[k][7];
                } /* else if x[k][1] == x[k][2] &&
                          x[k][2] == x[k][4] &&
                          x[k][4] == x[k][6] {
                    ans1 = x[k][0];
                    ans2 = x[k][3];
                    ans3 = x[k][5];
                    ans4 = x[k][7];
                }  *//* else if x[k][1] == x[k][3] &&
                          x[k][3] == x[k][5] &&
                          x[k][5] == x[k][7] {
                    ans1 = x[k][0];
                    ans2 = x[k][2];
                    ans3 = x[k][4];
                    ans4 = x[k][6];
                }  *//* else if x[k][1] == x[k][3] &&
                          x[k][3] == x[k][5] &&
                          x[k][5] == x[k][6] {
                    ans1 = x[k][0];
                    ans2 = x[k][2];
                    ans3 = x[k][4];
                    ans4 = x[k][7];
                }  */else if ((x[k][0] == x[k][2] || x[k][1] == x[k][2]) && (x[k][2] == x[k][4])) ||
                             ((x[k][3] == x[k][5] || x[k][3] == x[k][4]) && (x[k][1] == x[k][3])) {
                    ans1 = x[k][0];
                    ans2 = x[k][1];
                    ans3 = x[k][6];
                    ans4 = x[k][7];
                } else if x[k][0] == x[k][2] || x[k][1] == x[k][2] {
                    ans1 = x[k][4];
                    ans2 = x[k][5];
                    ans3 = x[k][6];
                    ans4 = x[k][7];
                } else {
                    ans1 = x[k][0];
                    ans2 = x[k][1];
                    ans3 = x[k][6];
                    ans4 = x[k][7];
                }
                break;
            } 

        }
        if ans {
            break;
        }
    }
    if ans {
        writeln!(out, "YES").ok();
        writeln!(out, "{} {} {} {}", ans1 + 1, ans2 + 1, ans3 + 1, ans4 + 1).ok();
    } else {
        writeln!(out, "NO").ok();
    }
}
