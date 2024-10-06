fn kmp(text: &str, pattern: &str) {
    let mut lps: Vec<usize> = Vec::with_capacity(pattern.len());

    for _ in 0..(pattern.len()) {
        lps.push(0);
    }

    let (mut prev, mut i) = (0 as usize, 1 as usize);
    
    while i < pattern.len() {
        if pattern.chars().nth(prev).unwrap() == pattern.chars().nth(i).unwrap() {
            lps[i] = lps[prev] + 1;
            prev += 1;
            i += 1;
        } else if prev == 0 {
            lps[i] = 0;
            i += 1
        }
        else {
            prev -= 1;
        }
    }

    println!("Text {text}");
    println!("Pattern {pattern}");
    println!("Longest Prefix Suffix Table: {lps:?}");

    let (mut i, mut j): (usize, usize) = (0, 1);
    let mut longest = 0;

    while i < text.len() {
        if text.chars().nth(i).unwrap() == pattern.chars().nth(j).unwrap() {
            (i, j) = (i + 1, j + 1);
        } else {
            if j == 1 {
                i += 1;
                j = 1;
            } else {
                j = lps[j - 1]
            }
        }

        if j >= pattern.len() {
            longest = i - text.len() as usize;
            break;
        }
    }

    println!("Text {text}");
    println!("Pattern {pattern}");
    println!("Longest {longest}");
}

fn main() {
    kmp("aacaaa", "aaa")
    // kmp("a", "aaacaaaa")
}
