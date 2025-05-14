
import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, View } from 'react-native';

import NavigationBar from '../../NavigationBar/NavigationBar';


export default function FindRecpiesScreen() {
  return (
    <View style={styles.container}>
      <Text>zakladka z kategoriami</Text>
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
