/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/keys-and-rooms                */
/* -------------------------------------------------------------------------- */

pub fn can_visit_all_rooms(rooms: Vec<Vec<i32>>) -> bool {
    let n = rooms.len();
    let mut visited = vec![false; n];

    let mut st = vec![];
    st.push(0);

    while let Some(top) = st.pop() {
        visited[top] = true;
        for nbr in rooms[top].iter() {
            let nbr = *nbr as usize;
            if !visited[nbr] {
                st.push(nbr);
            }
        }
    }

    return visited.iter().all(|x| -> bool { *x });
}
