
import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, View } from 'react-native';

import NavigationBar from '../../NavigationBar/NavigationBar';


export default function FavoriteRecepiesScreen() {
  return (
    <View style={styles.container}>
      <Text>ulubione przepisy</Text>
      <StatusBar style="auto" />
      <NavigationBar/>
    </View>
  );
}

const styles = StyleSheet.create({
  container: { 
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },

});
