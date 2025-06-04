import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";

import { Text } from "react-native";

import HomeScreen from "./Screens/Home/HomeScreen";
import FindRecipesScreen from "./Screens/FindRecipes/FindRecipesScreen";
import FavoriteRecipesScreen from "./Screens/FavoriteRecipes/FavoriteRecipesScreen";
import RecipeScreen from "./Screens/Recipe/RecipeScreen";
import CategorySreen from "./Screens/CategoryScreen/CategoryScreen";
import AiScreen from "./Screens/AiScreen/AiScreen.js"

import { Colors } from "./assets/cssVariables";


export default function App() {

  const Stack = createNativeStackNavigator();

  return (
     <NavigationContainer>
       <Stack.Navigator screenOptions={{ headerShown: false }}>
         <Stack.Screen name="home" component={HomeScreen} ></Stack.Screen>
         <Stack.Screen name="findRecipes" component={FindRecipesScreen}></Stack.Screen>
         <Stack.Screen name="favoriteRecipes" component={FavoriteRecipesScreen}></Stack.Screen>
         <Stack.Screen name="Ai" component={AiScreen}></Stack.Screen>
         <Stack.Screen name="Recipe" component={RecipeScreen} options={{ headerShown:true, title:'', headerStyle:{ backgroundColor:Colors.darkGreen }, headerTintColor:Colors.yellow}}></Stack.Screen>
         <Stack.Screen name="Category" component={CategorySreen}  options={{ headerShown:true, title:'', headerStyle:{ backgroundColor:Colors.darkGreen }, headerTintColor:Colors.yellow}}></Stack.Screen>
      </Stack.Navigator>
    </NavigationContainer>
  );
}

