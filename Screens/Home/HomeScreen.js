
import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, View } from 'react-native';

import NavigationBar from '../../NavigationBar/NavigationBar';

export default function HomeScreen() {
  return (
    <View style={styles.container}>
      <Text>aplikacja z przepisami(strona glowna)</Text>
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
