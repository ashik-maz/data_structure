#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        int screens = 0;
        
        // Each screen is 5x3 (15 cells)
        // Each 2x2 icon occupies 4 cells
        // Max 3 2x2 icons can fit on a screen
        
        // Calculate screens needed for 2x2 icons
        if (y > 0) {
            screens += (y + 2) / 3; // ceiling division for y by 3
        }
        
        // Calculate remaining cells after placing 2x2 icons
        int cells_used_by_2x2 = y * 4;
        int remaining_cells = screens * 15 - cells_used_by_2x2;

        // Place the 1x1 icons in the remaining cells
        if (x > 0) {
            if (remaining_cells >= x) {
                // All 1x1 icons can fit in the remaining cells
                x = 0;
            } else {
                // Not all 1x1 icons can fit, calculate remaining icons
                x -= remaining_cells;
            }
        }

        // Calculate additional screens needed for remaining 1x1 icons
        if (x > 0) {
            screens += (x + 14) / 15; // ceiling division for x by 15
        }

        cout << screens << endl;
    }

    return 0;
}
