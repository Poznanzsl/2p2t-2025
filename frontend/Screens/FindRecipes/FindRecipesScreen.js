
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
          <CategoryBox type = "Szybkie" emoji="🕒"/>
          <CategoryBox type="Polskie" emoji="🇵🇱"/>
        </View>
        <View style={styles.row}>
          <CategoryBox type="Włoskie" emoji="🇮🇹" />
          <CategoryBox type="Obiad" emoji="🍽️"/>
        </View>
        <View style={styles.row}>
          <CategoryBox type="Śniadanie" emoji="🍳"/>
          <CategoryBox type="Przystawki" emoji="🥗"/>
        </View>
      </ScrollView>
      <NavigationBar/>
    </View>
  );
}
