
import { StatusBar } from 'expo-status-bar';
import { ScrollView, StyleSheet, Text, View } from 'react-native';

import NavigationBar from '../../NavigationBar/NavigationBar';
import styles from './styleFindRecipesScreen.js'
import CategoryBox from '../../CategoryBox/CategoryBox.js';


export default function FindRecpiesScreen() {
  return (
    <View style={styles.container}>
      <StatusBar style="auto" />
      <ScrollView style = {styles.scrollView}>
        <View style={styles.row}>
          <CategoryBox type = "15 min" emoji="🕛"/>
          <CategoryBox type="30 min" emoji="🕛"/>
        </View>
        <View style={styles.row}>
          <CategoryBox type="1 h" emoji="🕛" />
          <CategoryBox type="obiad" emoji="🍽️"/>
        </View>
        <View style={styles.row}>
          <CategoryBox type="sniadanie" emoji="🍳"/>
          <CategoryBox type="przystawki" emoji="🥨"/>
        </View>
      </ScrollView>
      <NavigationBar/>
    </View>
  );
}
