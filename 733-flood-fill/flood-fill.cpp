class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c,
             int originalColor, int newColor) {

        int m = image.size();
        int n = image[0].size();

        // Out of bounds
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        // Not the original color
        if (image[r][c] != originalColor)
            return;

        // Change the color
        image[r][c] = newColor;

        // Visit 4 directions
        dfs(image, r + 1, c, originalColor, newColor); // down
        dfs(image, r - 1, c, originalColor, newColor); // up
        dfs(image, r, c + 1, originalColor, newColor); // right
        dfs(image, r, c - 1, originalColor, newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {

        int originalColor = image[sr][sc];

        // Important edge case
        if (originalColor == color)
            return image;

        dfs(image, sr, sc, originalColor, color);

        return image;
    }
};