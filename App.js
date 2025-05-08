import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";


import HomeScreen from "./Screens/Home/HomeScreen";
import FindRecpiesScreen from "./Screens/FindRecepies/FindRecepiesScreen";
import FavoriteRecepiesScreen from "./Screens/FavoriteRecepies/FavoriteRecepiesScreen";

export default function App() {

  const Stack = createNativeStackNavigator();

  return (
    <NavigationContainer>
      <Stack.Navigator screenOptions={{ headerShown: false }}>
        <Stack.Screen name="home" component={HomeScreen}></Stack.Screen>
        <Stack.Screen name="findRecepies" component={FindRecpiesScreen}></Stack.Screen>
        <Stack.Screen name="favoriteRecepies" component={FavoriteRecepiesScreen}></Stack.Screen>
      </Stack.Navigator>
    </NavigationContainer>
  );
}

