import { useNavigation } from "@react-navigation/native";
import { useEffect, useState } from "react";
import { ScrollView, Text, View } from "react-native";

import recipeDate from '../../assets/Recipe.json';
import RecipeCard from "../../RecipeCard/RecipeCard.js"
import styles from "../CategoryScreen/styleCategoryScreen.js"


export default function CategoryScreen(props){

    const {type} =  (props.route.params? props.route.params : "none" );
    const navigation = useNavigation();
    let recipeList =[] ;
    let [isRecipeNull , setisRecipeNull] = useState(false);

    if(type == "Szybkie"){
        recipeList = recipeDate.filter((r) => { return r.type == "Szybkie"});
    }
    else if(type == "Polskie"){
        recipeList = recipeDate.filter((r) => { return r.type == "Polskie"});
    }
    else if(type == "Włoskie"){
        recipeList = recipeDate.filter((r) => { return r.type == "Włoskie"});
    }
    else if(type == "Obiad"){
        recipeList = recipeDate.filter((r) => { return r.type == "Obiad"});
    }
    else if(type == "Śniadanie"){
        recipeList = recipeDate.filter((r) => { return r.type == "Śniadanie"});
    }
    else if(type == "Przystawki"){
        recipeList = recipeDate.filter((r) => { return r.type == "Przystawki"});
    }

    useEffect(()=>{

        
        if(recipeList.length == 0){
            setisRecipeNull(true);
        }


        navigation.setOptions({
            title: type,
            headerTitleAlign : 'center',
            headerTitleStyle:{
                fontSize:30,
             }
        });

    },[]);
    
    return(
        <View style = { styles.cotainer} >
            {isRecipeNull && 
            <View style = {styles.nullRecie}> 
                <Text> nie ma przepisow </Text> 
            </View>}

            {!isRecipeNull &&     
            <ScrollView style = {styles.scrollView}>
                    {recipeList.map((r) => { 
                        return <RecipeCard key={r.id} name= {r.name} time= {r.time} id={r.id}></RecipeCard>
                    })}
            </ScrollView>}
        </View>

    )
}