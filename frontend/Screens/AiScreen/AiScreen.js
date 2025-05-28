
import { StatusBar } from 'expo-status-bar';
import { Pressable, StyleSheet, Text, View } from 'react-native';

import styles from '../AiScreen/styleAiScreen.js'
import NavigationBar from '../../NavigationBar/NavigationBar';
import { useEffect, useState } from 'react';

import RecipeCard from '../../RecipeCard/RecipeCard.js';


export default function AiScreen() {

  let [recipeData , setRecipeData] = useState();
  let [isThereRecipe , setIsThereRecipe] = useState(false);

  async function generateRecipe(){
    console.log("elo");
   let respond = await fetch("https://maniowy.lm.r.appspot.com/api");
   respond = await respond.json();
      
   // const cleanResponse = respond.data.substring(8,respond.data.length - 5 );

    const cleanResponse = respond.data;
    let recipe;
    do{
      try{
      recipe = JSON.parse(cleanResponse);
      }
      catch{
        console.log("error");
        break;
      }

    }while( recipe == undefined)

    console.log(recipe);
    setRecipeData(recipe);
    setIsThereRecipe(true);
 }                           


  return (
    <>
      {!isThereRecipe &&  (
       <View style={styles.container}>
        <Text>ai tworzy przepisy</Text>
        <Pressable style = {styles.button} onPress={() => generateRecipe()}> 
          <Text>generuj</Text> 
        </Pressable>
        <StatusBar style="auto" />
        <NavigationBar/>
      </View>)}


r
      {isThereRecipe &&
        <View style={styles.container}>
          <RecipeCard key = {0} id = {recipeData.id} name ={recipeData.name}  time ={recipeData.time} /> 

          <Pressable style = {styles.button} onPress={generateRecipe}> 
            <Text>generuj</Text> 
          </Pressable>
          <NavigationBar/>
        </View>
      }
    </>
  );
}
                                          
