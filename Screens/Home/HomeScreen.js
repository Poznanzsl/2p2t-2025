
import NavigationBar from '../../NavigationBar/NavigationBar';
import Recipe from '../../Recipes/Recipe';
import styles from './styleHomeScreen.js';
import dataRecipes from "../../assets/Recipe.json";

import { StatusBar } from 'expo-status-bar';
import { ScrollView,StyleSheet, Text, View } from 'react-native';



export default function Home() {
  return (
    <View style={styles.container}>
      <Text style= {styles.text}>strona glowna</Text>
      <StatusBar style="auto" />

      <ScrollView style={styles.boxRecipe}>
        {dataRecipes.map(recipe=> (
          <Recipe key = {recipe.id} name = {recipe.name} time = {recipe.time}></Recipe>
        ))}
      </ScrollView>
      <NavigationBar/>
    </View>
  );
}
