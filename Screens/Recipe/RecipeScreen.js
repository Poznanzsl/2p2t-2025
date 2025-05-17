import { Text, View } from "react-native";
import styles from './styleRecipeScreen.js';
import dataRecipes from '../../assets/Recipe.json';

export default function RecipeScreen(props){

    const {id} =  props.route.params;
    const recipe = dataRecipes.find((r) => r.id == id);
    return(
        <View style={styles.container}>
            <Text style ={styles.header}>{recipe.name}</Text>
            <Text style={styles.time}>• czas : {recipe.time}min</Text>
        </View>    
    );
    
}

