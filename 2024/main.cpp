bool check(int x, int y) {
    if (x < 1 || y < 1 || x > 5) return false;
    if (x == 1 && y > 3) return false;
    if (x == 2 && y > 4) return false;
    if (x == 3 && y > 5) return false;
    if (x == 4 && y > 4) return false;
    if (x == 5 && y > 3) return false;
    return true;
}
