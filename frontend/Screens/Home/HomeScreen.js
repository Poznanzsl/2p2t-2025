
import NavigationBar from '../../NavigationBar/NavigationBar';
import RecipeCard from '../../RecipeCard/RecipeCard.js';
import styles from './styleHomeScreen.js';
import dataRecipes from "../../assets/Recipe.json";

import { StatusBar } from 'expo-status-bar';
import { ScrollView, StyleSheet, Text, View } from 'react-native';
import { useEffect } from 'react';
import * as PhoneNavBar from 'expo-navigation-bar';





export default function Home() {

  return (
    <View style={styles.container}>
      <View style ={styles.header}>
         <Text style= {styles.textHeader}>Yum & Done</Text>
       </View>
      <StatusBar backgroundColor='#2C3930' style='dark'  translucent={false} />

      <ScrollView style={styles.boxRecipe}>

        <Text style={styles.textEntry}>Witaj w naszej aplikacji z przepisami kulinarnymi! Znajdziesz tu sprawdzone receptury na pyszne dania –
           od prostych śniadań po wykwintne kolacje. Każdy przepis zawiera jasne instrukcje i listę składników,
            dzięki czemu gotowanie staje się przyjemnością. Niezależnie od poziomu zaawansowania, 
            znajdziesz tu coś dla siebie!</Text>

        <Text style= {styles.text}>Najbardziej Popularne Przepisy:</Text>

        {dataRecipes.map(recipe=> (
          <RecipeCard key = {recipe.id} id = {recipe.id} name = {recipe.name} time = {recipe.time}></RecipeCard>
        ))}
      </ScrollView>
      <NavigationBar/> 
    </View>
  );
  
}
