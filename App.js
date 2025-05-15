import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";


import HomeScreen from "./Screens/Home/HomeScreen";
import FindRecipesScreen from "./Screens/FindRecipes/FindRecipesScreen";
import FavoriteRecipesScreen from "./Screens/FavoriteRecipes/FavoriteRecipesScreen";


export default function App() {

  const Stack = createNativeStackNavigator();

  return (
    <NavigationContainer>
      <Stack.Navigator screenOptions={{ headerShown: false }}>
        <Stack.Screen name="home" component={HomeScreen}></Stack.Screen>
        <Stack.Screen name="findRecipes" component={FindRecipesScreen}></Stack.Screen>
        <Stack.Screen name="favoriteRecipes" component={FavoriteRecipesScreen}></Stack.Screen>
      </Stack.Navigator>
    </NavigationContainer>
  );
}

