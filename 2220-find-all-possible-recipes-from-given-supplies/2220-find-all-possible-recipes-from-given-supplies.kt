class Solution {
    fun findAllRecipes(recipes: Array<String>, ingredients: List<List<String>>, supplies: Array<String>): List<String> {
        val availableSupplies = supplies.toHashSet()
        val recipeToIngredients = mutableMapOf<String, List<String>>()
        val visited = mutableMapOf<String, Int>()
        val result = mutableListOf<String>()

        for (i in recipes.indices) {
            recipeToIngredients[recipes[i]] = ingredients[i]
        }

        fun canMake(recipe: String): Boolean {
            if (visited.containsKey(recipe)) {
                return visited[recipe] == 1
            }

            if (recipe in availableSupplies) {
                return true
            }

            if (recipe !in recipeToIngredients) {
                return false
            }

            visited[recipe] = 0

            for (ingredient in recipeToIngredients[recipe]!!) {
                if (!canMake(ingredient)) {
                    visited[recipe] = -1
                    return false
                }
            }

            visited[recipe] = 1
            result.add(recipe)
            return true
        }

        for (recipe in recipes) {
            canMake(recipe)
        }

        return result
    }
}