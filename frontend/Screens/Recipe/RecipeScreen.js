import { Text, View } from "react-native";
import styles from './styleRecipeScreen.js';
import dataRecipes from '../../assets/Recipe.json';
import { Colors } from "../../assets/cssVariables";
import { Image } from 'react-native';
import fotos from "../../assets/fotos.js";
import { ScrollView, StyleSheet,} from 'react-native';

export default function RecipeScreen({ route }) {
  const { id } = route.params;
  const recipe = dataRecipes. find((r)=> r.id === id);
  const imageSource = recipe.foto ? fotos[recipe.foto] : null;

    return(
        <ScrollView style={styles.container}>
            <Text style ={styles.header}>{recipe.name}</Text>
            {imageSource && <Image source={imageSource} style={styles.fotos}></Image> }
            <Text style={styles.time}><Text style={{color: Colors.yellow}}>Czas: </Text> {recipe.time}min</Text>
            <Text style={styles.skladniki}><Text style={{color: Colors.yellow}}>Składniki: </Text> {recipe.skladniki}</Text>
            <Text style={styles.opis}><Text style={{color: Colors.yellow}}>Przygotowanie:</Text> {recipe.opis}</Text>
        </ScrollView>    
    );
    
}
