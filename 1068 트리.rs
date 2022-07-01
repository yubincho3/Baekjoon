// 트리 입력 받고, 지울 노드의 연결을 끊어버리고선 루트를 시작으로 그래프 탐색을 하면 된다.
// 지울 노드가 루트일 때를 조심하면 간단히 풀 수 있지만 러스트 배우는 겸 문제 풀이에 썼다.
// 이렇게 깐깐한 언어&컴파일러는 처음 본 것 같다...

fn read_ints() -> Vec<i16>
{
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("");
    s.split_whitespace().map(|x| x.parse::<i16>().unwrap()).collect::<Vec<i16>>()
}

fn dfs(arr: &Vec<Vec<usize>>, now: usize) -> i16
{
    if arr[now].len() == 0
    {
        return 1;
    }

    let mut ret = 0;
    for i in arr[now].iter()
    {
        ret += dfs(arr, *i);
    }

    return ret;
}

fn main()
{
    let mut arr: Vec<Vec<usize>> = std::iter::repeat(vec![]).take(read_ints()[0] as usize).collect::<Vec<_>>();
    let mut root: usize = 0;

    for (i, node) in read_ints().iter().enumerate()
    {
        if *node == -1
        {
            root = i;
        }
        else
        {
            arr[*node as usize].push(i);
        }
    }
    
    let tar = read_ints()[0] as usize;
    
    'out: for i in 0..arr.len()
    {
        for j in 0..arr[i].len()
        {
            if arr[i][j] == tar
            {
                arr[i].remove(j);
                break 'out;
            }
        }
    } arr[tar].clear();

    print!("{}", dfs(&arr, root) - (if tar == root {1} else {0}));
}
